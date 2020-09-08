#include "TestController.h"

void TestController::asyncHandleHttpRequest(const HttpRequestPtr &req,
                                            std::function<void(const HttpResponsePtr &)> &&callback) {
    HttpResponsePtr resp{HttpResponse::newHttpResponse()};
    resp->setStatusCode(k200OK);
    resp->setContentTypeCode(CT_TEXT_HTML);
    resp->setBody("Hello world!");
    callback(resp);
}