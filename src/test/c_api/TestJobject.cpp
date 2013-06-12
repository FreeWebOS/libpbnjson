// @@@LICENSE
//
//      Copyright (c) 2009-2012 Hewlett-Packard Development Company, L.P.
//      Copyright (c) 2013 LG Electronics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// LICENSE@@@

#include <gtest/gtest.h>
#include <pbnjson.h>
#include <string>
#include <algorithm>

using namespace std;

class JobjRemove
    : public testing::Test
{
protected:
	virtual void SetUp()
	{
		obj = jobject_create();
		jobject_put(obj, J_CSTR_TO_JVAL("a"), jnumber_create_i32(5));
		jobject_put(obj, J_CSTR_TO_JVAL("b"), jstring_create("Hello, world"));
		jobject_put(obj, J_CSTR_TO_JVAL("c"), jnumber_create_i32(13));
		jobject_put(obj, J_CSTR_TO_JVAL("d"), jboolean_create(true));
		jobject_put(obj, J_CSTR_TO_JVAL("e"), jboolean_create(false));
	}

	virtual void TearDown()
	{
		j_release(&obj);
	}

	jvalue_ref obj;

	string GetIteration() const
	{
		string res;
		for (jobject_iter it = jobj_iter_init(obj); jobj_iter_is_valid(it); it = jobj_iter_next(it))
		{
			jobject_key_value key_value;
			jobj_iter_deref(it, &key_value);
			res.push_back(jstring_get_fast(key_value.key).m_str[0]);
		}
		std::sort(res.begin(), res.end());
		return res;
	}
};

TEST_F(JobjRemove, ObjectRemoveAndIterate)
{
	jobject_remove(obj, j_cstr_to_buffer("b"));
	ASSERT_EQ(GetIteration(), "acde");
	jobject_remove(obj, j_cstr_to_buffer("a"));
	ASSERT_EQ(GetIteration(), "cde");
	jobject_remove(obj, j_cstr_to_buffer("e"));
	ASSERT_EQ(GetIteration(), "cd");
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
