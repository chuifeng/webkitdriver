/*
Copyright 2007-2009 WebDriver committers
Copyright 2007-2009 Google Inc.
Portions copyright 2007 ThoughtWorks, Inc

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

     http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

package org.openqa.selenium.webkit;

import java.lang.reflect.Method;
import java.nio.ByteBuffer;
import java.util.ArrayList;

import org.openqa.selenium.WebDriverException;

public class WebKitSerializer {
  private static final byte methodType   = 0;
  private static final byte longType     = 1;
  private static final byte intType      = 2;
  private static final byte doubleType   = 3;
  private static final byte stringType   = 4;
  private static final byte booleanType  = 5;
  private static final byte arrayType    = 6;

  public ByteBuffer putMethodIntoStream(Method method, Object args[]) throws WebDriverException {
    ByteBuffer stream = ByteBuffer.allocate(30000);
    serialize(stream, method);
    for (int i = 0; i < method.getParameterTypes().length; i++)
        serialize(stream, args[i]);
    return stream;
  }

  public Object invokeMethodFromStream(ByteBuffer stream) throws WebDriverException {
    Object method = deserialize(stream);
    if (!(method instanceof Method)) 
        throw new WebDriverException("incorrect serialization format");
    ;

    ArrayList args = new ArrayList();
    for (int i = 0; i < ((Method)method).getParameterTypes().length; i++)
        args.add(deserialize(stream));

    // method invocation goes here
    return null;
  } 

  public void serialize(ByteBuffer stream, Object object) {
    if (object instanceof Long) {
      stream.put(longType);
      stream.putInt(-1);
      stream.putLong((Long)object);
    }
    else if (object instanceof Integer) {
      stream.put(intType);
      stream.putInt(-1);
      stream.putInt((Integer)object);
    }
    else if (object instanceof Double) {
      stream.put(doubleType);
      stream.putInt(-1);
      stream.putDouble((Double)object);
    } else if (object instanceof Boolean) {
      stream.put(booleanType);
      stream.putInt(-1);
      if ((Boolean)object) stream.put((byte)1);
      else stream.put((byte)0);
    } else if (object instanceof Object[]) {
      Object[] array = (Object[])object;
      stream.put(arrayType);
      stream.putInt(array.length);
      for (int i = 0; i < array.length; i++) {
        serialize(stream, array[i]);
      }
    } else if (object instanceof String) {
      stream.put(stringType);
      stream.putInt(((String)object).length());
      stream.asCharBuffer().put((String)object);
    } else if (object instanceof Method){
      stream.put(methodType);
      stream.putInt(((Method)object).getName().length());
      stream.asCharBuffer().put(((Method)object).getName());
    } else {
      throw new WebDriverException("Unknow data type during serialization");
    }

  }

  private Object deserialize(ByteBuffer stream) {
    byte type = stream.get();
    int size = stream.getInt();
    switch (type) {
      case longType:
        return stream.getLong();
      case intType:
        return stream.getInt();
      case doubleType:
        return stream.getDouble();
      case booleanType:
        byte bool = stream.get();
        if (bool == 0) return new Boolean(false);
        return new Boolean(true);
      case stringType:
        return stream.asCharBuffer().subSequence(stream.position(), stream.position() + size).toString();
      case arrayType:
        ArrayList array = new ArrayList();
        for (int i = 0; i < size; i++)
          array.add(stream);
        return array;
      case methodType:
        // method lookup goes here
        return null;
      default:
        throw new WebDriverException("Unknown data type during deserialization");
    }
  }
} 