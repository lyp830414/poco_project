#pragma once

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

using namespace Poco;
using namespace std;

class MyApplication : public Util::Application
{
public:
    MyApplication( )
    {
        m_helpRequested =  false ;
    }
    void initialize( Application& self );
    void uninitialize( );

    void defineOptions( Util::OptionSet& options);
    void handleHelp(const std::string& name, const std::string& value );
    void handleDaemon(const std::string& name, const std::string& value);
    int main(const std::vector<std::string>& args);
private:
    bool m_helpRequested;//如果传参数进来那么此变量变为 true 在main() 方法就不要做其他的事情直接退出。
    void beDaemon( );
};