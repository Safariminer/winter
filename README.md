# Winter
## Experimental driver-structured game engine

Winter is a game engine whose internal structure uses "driver" classes to manage cross-platform compatibility, in theory only needing C++'s standard template library as a dependency

## Building and Dependencies

Winter requires a fairly modern version of the Standard Template Library (minimum C++23).

Building on Windows right now is only supported on MSVC with the latest edition of Visual Studio (2026 at the time of writing this). The Windows drivers only require SDL3, of which the download and install instructions can be found [here](DEPENDENCIES.txt), and OpenGL's libraries which come with the Windows SDK in Visual Studio.

Building on/for any other platforms currently isn't supported.

## Documentation
Winter uses Doxygen for documentation. There is a Doxyfile that allows you to build HTML documentation of every part of the engine. Documentation is not currently complete, but some classes and namespaces already have explanatory documentation.

## Licensing
See [LICENSE](LICENSE).