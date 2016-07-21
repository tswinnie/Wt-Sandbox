#include <Wt/WApplication>
#include <Wt/WPushButton>
#include <Wt/WContainerWidget>

using namespace Wt;

class HelloWorld : public WContainerWidget{

public:
    HelloWorld(WContainerWidget *parent = 0);
};

HelloWorld::HelloWorld(WContainerWidget *parent) : WContainerWidget(parent) {

    WContainerWidget *container = new WContainerWidget(this);
    WPushButton *button = new WPushButton;
    button->setText("Hello, World!");
    button->setStyleClass("btn btn-primary");
    container->addWidget(button);

}

WApplication* createApp(const WEnvironment &env){

    WApplication *app = new WApplication(env);
    app->setTitle("Template Project");

    //CSS
    app->useStyleSheet("CSS/bootstrap.min.css");
    app->useStyleSheet("CSS/mdb.min.css");
    app->useStyleSheet("CSS/style.css");

    //JS
    app->requireJQuery("JS/jquery-2.2.3.min.js");
    app->require("JS/tether.min.js");
    app->require("JS/bootstrap.min.js");
    app->require("JS/mdb.min.js");

    app->root()->addWidget(new HelloWorld);

    return app;
}

int main(int argc, char **argv) {
    return WRun(argc,argv, &createApp);
}