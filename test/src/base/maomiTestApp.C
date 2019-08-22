//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "maomiTestApp.h"
#include "maomiApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<maomiTestApp>()
{
  InputParameters params = validParams<maomiApp>();
  return params;
}

maomiTestApp::maomiTestApp(InputParameters parameters) : MooseApp(parameters)
{
  maomiTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

maomiTestApp::~maomiTestApp() {}

void
maomiTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  maomiApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"maomiTestApp"});
    Registry::registerActionsTo(af, {"maomiTestApp"});
  }
}

void
maomiTestApp::registerApps()
{
  registerApp(maomiApp);
  registerApp(maomiTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
maomiTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  maomiTestApp::registerAll(f, af, s);
}
extern "C" void
maomiTestApp__registerApps()
{
  maomiTestApp::registerApps();
}
