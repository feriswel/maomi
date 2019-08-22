#include "maomiApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<maomiApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

maomiApp::maomiApp(InputParameters parameters) : MooseApp(parameters)
{
  maomiApp::registerAll(_factory, _action_factory, _syntax);
}

maomiApp::~maomiApp() {}

void
maomiApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"maomiApp"});
  Registry::registerActionsTo(af, {"maomiApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
maomiApp::registerApps()
{
  registerApp(maomiApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
maomiApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  maomiApp::registerAll(f, af, s);
}
extern "C" void
maomiApp__registerApps()
{
  maomiApp::registerApps();
}
