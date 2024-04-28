
#include "app.hpp"
int main() {
    App &app = App::Instance();

    app.Run();
    return 0;
}
