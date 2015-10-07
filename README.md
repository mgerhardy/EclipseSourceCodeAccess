## How to setup and use this?
[Unreal Howto](https://wiki.unrealengine.com/Linux_Known_Issues#C.2B.2B_projects_and_IDE.27s)

## Note
Based on the [qt creator source access implementation](https://github.com/fire/QtCreatorSourceCodeAccess)

## Instructions
Clone this repository to ```Engine/Plugins/Developer``` in your UnrealEngine directory.

Add the following to the file ```Engine/Config/Linux/LinuxEngine.ini```

```
[/Script/SourceCodeAccess.SourceCodeAccessSettings]
PreferredAccessor=EclipseSourceCodeAccessor
```
