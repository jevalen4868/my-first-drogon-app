#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

using std::function;
using std::string;

namespace myapp {
    struct User {
        string userName;
        string email;
        string address;
    };
};

namespace drogon {
    template<>
    inline myapp::User fromRequest(const HttpRequest &req) {
        auto json {req.getJsonObject()};
        myapp::User user;
        if(json) {
            user.userName = (*json)["name"].asString();
            user.email = (*json)["email"].asString();
            user.address = (*json)["address"].asString();
        }
        return user;
    }
}

namespace demo {
    namespace v1 {
        class User : public drogon::HttpController<User> {
        public:
            METHOD_LIST_BEGIN
                //use METHOD_ADD to add your custom processing function here;
                //METHOD_ADD(User::get,"/{2}/{1}",Get);//path is /demo/v1/User/{arg2}/{arg1}
                //METHOD_ADD(User::your_method_name,"/{1}/{2}/list",Get);//path is /demo/v1/User/{arg1}/{arg2}/list
                //ADD_METHOD_TO(User::your_method_name,"/absolute/path/{1}/{2}/list",Get);//path is /absolute/path/{arg1}/{arg2}/list
                METHOD_ADD(User::login, "/token?userId={1}&passwd={2}", Post);
                METHOD_ADD(User::getInfo, "/{1}/info?token={2}", Get);
                ADD_METHOD_TO(User::newUser, "/users", Post);
            METHOD_LIST_END

            void login(const HttpRequestPtr &req,
                           function<void(const HttpResponsePtr &)> &&callback,
                           string &&userId,
                           const string &password);
            void getInfo(const HttpRequestPtr &req,
                    function<void (const HttpResponsePtr &)> &&callback,
                    string userId,
                    const string &token) const;
            // Object can replace the incoming req.
            void newUser(myapp::User &&pNewUser,
                    function<void (const HttpResponsePtr &)> &&callback) const;

            /* Alternate Implementation
            void newUser(const HttpRequestPtr &req,
                    function <void (const HttpResponsePtr &)> &&callback,
                    myapp::User &&pNewUser) const;
                    */

            // your declaration of processing function maybe like this:
            // void get(const HttpRequestPtr& req,std::function<void (const HttpResponsePtr &)> &&callback,int p1,std::string p2);
            // void your_method_name(const HttpRequestPtr& req,std::function<void (const HttpResponsePtr &)> &&callback,double p1,int p2) const;
        };
    }
}
