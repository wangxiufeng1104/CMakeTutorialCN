#include <iostream>
#include <fstream>
#include <curl/curl.h>

// 回调函数，用于写入下载的数据到文件
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    std::ofstream* file = static_cast<std::ofstream*>(userp);
    file->write(static_cast<char*>(contents), size * nmemb);
    return size * nmemb;
}

int main() {
    CURL* curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl) {
        // 设置要下载的URL
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.baidu.com");

        // 设置回调函数及文件指针，用于写入下载的数据
        std::ofstream file("baidu.html", std::ios::binary);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &file);

        // 执行下载
        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;

        // 清理curl资源
        curl_easy_cleanup(curl);
        file.close();
    }

    curl_global_cleanup();

    return 0;
}
