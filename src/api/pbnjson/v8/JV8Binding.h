/* @@@LICENSE
*
*      Copyright (c) 2012 Hewlett-Packard Development Company, L.P.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
LICENSE@@@ */

/*
 * JV8Binding.h
 *
 *  Created on: Feb 18, 2010
 */

#ifndef JV8BINDING_H_
#define JV8BINDING_H_

#include <v8.h>

namespace pbnjson {

#if 0
	static v8::Handle<v8::Value> stringifyObject(const v8::Arguments& args)
	{
		using namespace v8;

		Local<Value> object = args[0];
		Local<String> result;

		if (object->IsUndefined())
	}
#endif

	v8::Handle<v8::Value> parseString(const v8::Arguments& args);

	void InitJSON2(v8::Handle<v8::ObjectTemplate>& globalTemplate);
}

#endif /* JV8BINDING_H_ */
