namespace UnrealBuildTool.Rules
{
	public class EclipseSourceCodeAccess : ModuleRules
	{
		public EclipseSourceCodeAccess(TargetInfo Target)
		{
		 	PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					"DesktopPlatform",
					"SourceCodeAccess"
				}
			);
		}
	}
}
