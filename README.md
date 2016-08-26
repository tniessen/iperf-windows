Building
--------

First, obtain a copy of this repository and its dependencies:

    git clone --recursive https://github.com/tniessen/iperf-windows

Open `iperf.sln` in Visual Studio and choose "Debug" or "Test Release"
as the build mode.

If the submodule `iperf` does not contain `src/iperf_config.h` and
`src/version.h`, you will need to add these files based on available templates
templates (`*.in`).

Note: If you are using Visual Studio 2015 or later, you might need to

    #define HAVE_STRUCT_TIMESPEC

License
-------

See LICENSE file.
