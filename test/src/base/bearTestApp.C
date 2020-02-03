//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "bearTestApp.h"
#include "bearApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
bearTestApp::validParams()
{
  InputParameters params = bearApp::validParams();
  return params;
}

bearTestApp::bearTestApp(InputParameters parameters) : MooseApp(parameters)
{
  bearTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

bearTestApp::~bearTestApp() {}

void
bearTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  bearApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"bearTestApp"});
    Registry::registerActionsTo(af, {"bearTestApp"});
  }
}

void
bearTestApp::registerApps()
{
  registerApp(bearApp);
  registerApp(bearTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
bearTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  bearTestApp::registerAll(f, af, s);
}
extern "C" void
bearTestApp__registerApps()
{
  bearTestApp::registerApps();
}
