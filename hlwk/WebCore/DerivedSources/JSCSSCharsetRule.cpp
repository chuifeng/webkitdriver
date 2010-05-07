/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"
#include "JSCSSCharsetRule.h"

#include "CSSCharsetRule.h"
#include "KURL.h"
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSCSSCharsetRule);

/* Hash table */

static const HashTableValue JSCSSCharsetRuleTableValues[3] =
{
    { "encoding", DontDelete, (intptr_t)jsCSSCharsetRuleEncoding, (intptr_t)setJSCSSCharsetRuleEncoding },
    { "constructor", DontEnum|ReadOnly, (intptr_t)jsCSSCharsetRuleConstructor, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSCSSCharsetRuleTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 3, JSCSSCharsetRuleTableValues, 0 };
#else
    { 4, 3, JSCSSCharsetRuleTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSCSSCharsetRuleConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSCSSCharsetRuleConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSCSSCharsetRuleConstructorTableValues, 0 };
#else
    { 1, 0, JSCSSCharsetRuleConstructorTableValues, 0 };
#endif

class JSCSSCharsetRuleConstructor : public DOMConstructorObject {
public:
    JSCSSCharsetRuleConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSCSSCharsetRuleConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSCSSCharsetRulePrototype::self(exec, globalObject), None);
    }
    virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
    virtual bool getOwnPropertyDescriptor(ExecState*, const Identifier&, PropertyDescriptor&);
    virtual const ClassInfo* classInfo() const { return &s_info; }
    static const ClassInfo s_info;

    static PassRefPtr<Structure> createStructure(JSValue proto) 
    { 
        return Structure::create(proto, TypeInfo(ObjectType, StructureFlags), AnonymousSlotCount); 
    }
    
protected:
    static const unsigned StructureFlags = OverridesGetOwnPropertySlot | ImplementsHasInstance | DOMConstructorObject::StructureFlags;
};

const ClassInfo JSCSSCharsetRuleConstructor::s_info = { "CSSCharsetRuleConstructor", 0, &JSCSSCharsetRuleConstructorTable, 0 };

bool JSCSSCharsetRuleConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSCSSCharsetRuleConstructor, DOMObject>(exec, &JSCSSCharsetRuleConstructorTable, this, propertyName, slot);
}

bool JSCSSCharsetRuleConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSCSSCharsetRuleConstructor, DOMObject>(exec, &JSCSSCharsetRuleConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSCSSCharsetRulePrototypeTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSCSSCharsetRulePrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSCSSCharsetRulePrototypeTableValues, 0 };
#else
    { 1, 0, JSCSSCharsetRulePrototypeTableValues, 0 };
#endif

const ClassInfo JSCSSCharsetRulePrototype::s_info = { "CSSCharsetRulePrototype", 0, &JSCSSCharsetRulePrototypeTable, 0 };

JSObject* JSCSSCharsetRulePrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSCSSCharsetRule>(exec, globalObject);
}

const ClassInfo JSCSSCharsetRule::s_info = { "CSSCharsetRule", &JSCSSRule::s_info, &JSCSSCharsetRuleTable, 0 };

JSCSSCharsetRule::JSCSSCharsetRule(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<CSSCharsetRule> impl)
    : JSCSSRule(structure, globalObject, impl)
{
}

JSObject* JSCSSCharsetRule::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSCSSCharsetRulePrototype(JSCSSCharsetRulePrototype::createStructure(JSCSSRulePrototype::self(exec, globalObject)));
}

bool JSCSSCharsetRule::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSCSSCharsetRule, Base>(exec, &JSCSSCharsetRuleTable, this, propertyName, slot);
}

bool JSCSSCharsetRule::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSCSSCharsetRule, Base>(exec, &JSCSSCharsetRuleTable, this, propertyName, descriptor);
}

JSValue jsCSSCharsetRuleEncoding(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSCSSCharsetRule* castedThis = static_cast<JSCSSCharsetRule*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    CSSCharsetRule* imp = static_cast<CSSCharsetRule*>(castedThis->impl());
    JSValue result = jsStringOrNull(exec, imp->encoding());
    return result;
}

JSValue jsCSSCharsetRuleConstructor(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSCSSCharsetRule* domObject = static_cast<JSCSSCharsetRule*>(asObject(slot.slotBase()));
    return JSCSSCharsetRule::getConstructor(exec, domObject->globalObject());
}
void JSCSSCharsetRule::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    lookupPut<JSCSSCharsetRule, Base>(exec, propertyName, value, &JSCSSCharsetRuleTable, this, slot);
}

void setJSCSSCharsetRuleEncoding(ExecState* exec, JSObject* thisObject, JSValue value)
{
    JSCSSCharsetRule* castedThisObj = static_cast<JSCSSCharsetRule*>(thisObject);
    CSSCharsetRule* imp = static_cast<CSSCharsetRule*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    imp->setEncoding(valueToStringWithNullCheck(exec, value), ec);
    setDOMException(exec, ec);
}

JSValue JSCSSCharsetRule::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSCSSCharsetRuleConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}


}