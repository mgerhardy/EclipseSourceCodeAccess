## How to setup and use this?
[Unreal Howto](https://wiki.unrealengine.com/Linux_Known_Issues#C.2B.2B_projects_and_IDE.27s)

Clone this repository to ```Engine/Plugins/Developer``` in your UnrealEngine directory.

Now rebuild the engine (or better, build the plugin).

Add the following to the file ```Engine/Config/Linux/LinuxEngine.ini```

(Keep in mind that ```Linux``` in that filepath might change to whatever OS you are using)

```
[/Script/SourceCodeAccess.SourceCodeAccessSettings]
PreferredAccessor=EclipseSourceCodeAccessor
```

In order to be able to find eclipse, some default paths are checked (like e.g. ```/usr/bin/eclipse```).
In addition to that you also can export the environment variable ```UE4_ECLIPSE_BINARY``` with the full path to the eclipse binary.

This plugin should work on Linux, Win32, Win64 and Mac.

## Note
Based on the [qt creator source access implementation](https://github.com/fire/QtCreatorSourceCodeAccess) and the included code lite source accessor.
