#include "bearApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
bearApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

bearApp::bearApp(InputParameters parameters) : MooseApp(parameters)
{
  bearApp::registerAll(_factory, _action_factory, _syntax);
}

bearApp::~bearApp() {}

void
bearApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"bearApp"});
  Registry::registerActionsTo(af, {"bearApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
bearApp::registerApps()
{
  registerApp(bearApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
bearApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  bearApp::registerAll(f, af, s);
}
extern "C" void
bearApp__registerApps()
{
  bearApp::registerApps();
}
