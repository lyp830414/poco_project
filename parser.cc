#include "Poco/Poco.h"
#include "Poco/Util/Application.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/HelpFormatter.h"
#include <iostream>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>

#include "rest.h"
#include "parser.h"

using namespace Poco;
using namespace std;

int argc=0;
char **argv=nullptr;

void MyApplication::initialize( Application& self )
{
    Util::Application::initialize( self );//帮我们初始化子系统，必须显示的调用。
    std::cout << "this is initialize\n";
}

void MyApplication::uninitialize( )
{
    Util::Application::uninitialize( );//帮我们关闭子系统，必须显示的调用。
    std::cout << "this is uninitialize\n";
}

void MyApplication::defineOptions( Util::OptionSet& options)
{
    Util::Application::defineOptions( options );//必须调用
    std::cout << "defineOptions被调用" << std::endl;
    options.addOption(
            Util::Option("help", "h",
                    "display help information on command line arguments")
                    .required(false)
                    .repeatable(false)
                    .callback(Util::OptionCallback < MyApplication >(this, &MyApplication::handleHelp))  );
    options.addOption(
            Util::Option("daemon", "", "Run application as a daemon.")
                .required(false)
                .repeatable(false)
                .callback(Util::OptionCallback<MyApplication>(this, &MyApplication::handleDaemon))  );
    options.addOption(
            Util::Option("dummy", "", "Run application as a daemon.")
                    .required(false)
                    .repeatable(false)
                    .callback(Util::OptionCallback<MyApplication>(this, &MyApplication::DummyMsg))  );
}

void MyApplication::handleHelp(const std::string& name, const std::string& value )
{
    m_helpRequested = true;
    Poco::Util::HelpFormatter helpFormatter( options() );
    helpFormatter.format(std::cout);
}


void MyApplication::handleDaemon(const std::string& name, const std::string& value)
{
    beDaemon();
}

void MyApplication::DummyMsg(const std::string& name, const std::string& value) {
    cout<<"hello Big Niu Niu!"<<endl;
}

void MyApplication::beDaemon()
{
    pid_t pid;
    if ((pid = fork()) < 0)
        throw SystemException("cannot fork daemon process");
    else if (pid != 0)
        exit(0);

    setsid();
    umask(0);

    FILE* fin  = freopen("/dev/null", "r+", stdin);
    if (!fin) throw Poco::OpenFileException("Cannot attach stdin to /dev/null");
    FILE* fout = freopen("/dev/null", "r+", stdout);
    if (!fout) throw Poco::OpenFileException("Cannot attach stdout to /dev/null");
    FILE* ferr = freopen("/dev/null", "r+", stderr);
    if (!ferr) throw Poco::OpenFileException("Cannot attach stderr to /dev/null");
}

int MyApplication::main(const std::vector<std::string>& args)
{
    if( !m_helpRequested )
    {
        std::cout << "this is main no help\n";
        while(1)
        {
            std::cout << "hello world" << std::endl;
            rest_main({""});
	    
            sleep( 3 );
        }
    }else
    {
        std::cout <<"this is main call help\n";
    }
    return Application::EXIT_OK;
}

///////////////////////////////////主函数////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
int main( int argc , char **argv )
{
            /*MyServerApp app;
	    app.run(::argc, ::argv);
	    return 0;*/
    try
    {
        MyApplication app;
        app.init( argc, argv );//在这里传主函数参数。
        app.run( );
    }catch( Poco::Exception &e )
    {
        std::cerr << "some error:  " << e.what() << std::endl;
    }
}
