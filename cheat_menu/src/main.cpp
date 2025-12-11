import std;
import types;
import gl;
import glfw;
import window;
import application;
import imgui;


auto glfw_error_callback(int error, char const* description) -> void {
    std::println(std::cerr, "GLFW Error: {}: {}", error, description);
};

auto main(i32 argc, char *argv[]) -> i32 {
    glfw::setErrorCallback(glfw_error_callback);
    if (!glfw::init()) return 0;

    while (true) {
        auto window = Window::Create("cheat_menu");
        if (!window) break;

        {
        auto ctx = imgui::createContext(nullptr);
        imgui::setCurrentContext(ctx);
        
        imgui::glfw::initForOpenGl(window->get(), true);
        imgui::gl::init("#version 460");

        imgui::Io& io = imgui::getIo();
        imgui::styleColorsDark(nullptr);
        io.Fonts->AddFontFromFileTTF("/usr/share/fonts/OTF/MonaspiceNeNerdFont-Regular.otf", 24.0f);
        io.Fonts->Build();

        while (true) {
            auto app = Application::Create(std::move(*window));
            if (!app) break;

            app->run();
            break;
        }
        
        imgui::gl::shutdown();
        imgui::glfw::shutdown();
        imgui::destroyContext(nullptr);
        }
        break;
    }

    glfw::terminate();

    std::println("returning 0...");
    return 0;
}
