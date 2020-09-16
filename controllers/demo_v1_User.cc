#include "demo_v1_User.h"

using namespace demo::v1;
//add definition of your processing function here
void User::login(const HttpRequestPtr &req, function<void(const HttpResponsePtr &)> &&callback, string &&userId,
                 const string &password) {
    LOG_DEBUG << "User " << userId << " login.";
    //auth
    Json::Value ret;
    ret["result"]="ok";
    ret["token"]= utils::getUuid();
    HttpResponsePtr resp { HttpResponse::newHttpJsonResponse(ret)};
    callback(resp);
}

void User::getInfo(const HttpRequestPtr &req, function<void(const HttpResponsePtr &)> &&callback, string userId,
                   const string &token) const {
    LOG_DEBUG << "User " << userId << " retrieving their info";
    // read data.
    Json::Value ret;
    ret["result"] = "ok";
    ret["user_name"] = "Jack";
    ret["user_id"] = userId;
    ret["gender"] = -1;
    HttpResponsePtr resp {HttpResponse::newHttpJsonResponse(ret)};
    callback(resp);
}

void User::newUser(myapp::User &&pNewUser, function<void(const HttpResponsePtr &)> &&callback) const {
    LOG_DEBUG << "New User called.";
    LOG_DEBUG << pNewUser.userName;
    LOG_DEBUG << pNewUser.address;
    LOG_DEBUG << pNewUser.email;
    Json::Value ret;
    ret["user_name"] = pNewUser.userName;
    ret["successful"] = true;
    callback(HttpResponse::newHttpJsonResponse(ret));
}
