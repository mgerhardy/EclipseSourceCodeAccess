#pragma once

#include "EclipseSourceCodeAccessor.h"

class FEclipseSourceCodeAccessModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	FEclipseSourceCodeAccessor& GetAccessor();

private:
	FEclipseSourceCodeAccessor EclipseSourceCodeAccessor;
};
