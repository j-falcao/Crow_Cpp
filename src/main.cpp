#include "crow.h"
#include <iostream>
#include <string>

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")
    ([](){ 
        crow::mustache::set_base("../src/templates/");
        auto page = crow::mustache::load("ficha7/index.html");
        return page.render();
    });

    CROW_ROUTE(app, "/pedro")
    ([](const crow::request&, crow::response& res) {
        // Set the appropriate Content-Type for the image
        res.set_header("Content-Type", "image/jpg");

        // Specify the path to the image file
        std::string imagePath = "../src/imagens/programmerTips.jpg";

        // Read the image file and serve it
        std::ifstream imageFile(imagePath, std::ios::in | std::ios::binary);

        if (imageFile.is_open()) {
            std::string imageContent((std::istreambuf_iterator<char>(imageFile)), std::istreambuf_iterator<char>());
            res.write(imageContent);
        } else {
            res.code = 404; // Not Found
            res.write("Image not found");
        }
        res.end();
    });



    app.port(42069).multithreaded().run();
    return 0;
}   