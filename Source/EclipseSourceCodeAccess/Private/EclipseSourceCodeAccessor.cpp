#include "EclipseSourceCodeAccessPrivatePCH.h"
#include "EclipseSourceCodeAccessor.h"
#include "DesktopPlatformModule.h"

#define LOCTEXT_NAMESPACE "EclipseSourceCodeAccessor"

// http://help.eclipse.org/juno/index.jsp?topic=%2Forg.eclipse.platform.doc.isv%2Freference%2Fmisc%2Fruntime-options.html

bool FEclipseSourceCodeAccessor::CanAccessSourceCode() const
{
	return true;
}

FName FEclipseSourceCodeAccessor::GetFName() const
{
	return FName("EclipseSourceCodeAccessor");
}

FText FEclipseSourceCodeAccessor::GetNameText() const
{
	return LOCTEXT("EclipseDisplayName", "Eclipse");
}

FText FEclipseSourceCodeAccessor::GetDescriptionText() const
{
	return LOCTEXT("EclipseDisplayDesc", "Open source code files with Eclipse");
}

bool FEclipseSourceCodeAccessor::OpenSolution()
{
	FString FullPath;
	FString SolutionFilenameWithoutExtension = TEXT("UE4");
	FString CodeSolutionFile = SolutionFilenameWithoutExtension + TEXT(".cproject");

	if (!FDesktopPlatformModule::Get()->GetSolutionPath(FullPath))
	{
		return false;
	}
	if (!FPaths::FileExists(FullPath))
	{
		return false;
	}
	FString Editor = FString(TEXT("eclipse"));
	FString Args = FString(TEXT(""));

	const FString NewFullPath = FString::Printf(TEXT("\"%s\""), *FullPath);

	Args.Append(NewFullPath);
	if (!FLinuxPlatformProcess::CreateProc(*Editor, *Args, true, true, false, nullptr, 0, nullptr, nullptr).IsValid())
	{
		return false;
	}
	return true;
}

bool FEclipseSourceCodeAccessor::OpenFileAtLine(const FString& FullPath, int32 LineNumber, int32 ColumnNumber)
{
	TArray<FString> Files(FullPath);
	return OpensourceFiles(Files);
}

bool FEclipseSourceCodeAccessor::OpenSourceFiles(const TArray<FString>& AbsoluteSourcePaths) 
{
	FString Editor = FString(TEXT("eclipse"));
	FString Args = FString(TEXT("--launcher.timeout 60 --launcher.openFile "));
	for (const FString& SourcePath : AbsoluteSourcePaths)
	{
		const FString NewSourcePath = FString::Printf(TEXT("\"%s\" "), *SourcePath);
		Args.Append(NewSourcePath);
	}
	if (!(FLinuxPlatformProcess::CreateProc(*Editor, *Args, true, true, false, nullptr, 0, nullptr, nullptr).IsValid()))
	{
		return false;
	}
	return true;
}

bool FEclipseSourceCodeAccessor::AddSourceFiles(const TArray<FString>& AbsoluteSourcePaths, const TArray<FString>& AvailableModules)
{
	return false;
}

bool FEclipseSourceCodeAccessor::SaveAllOpenDocuments() const
{
	return false;
}

void FEclipseSourceCodeAccessor::Tick(const float DeltaTime)
{
}

#undef LOCTEXT_NAMESPACE
