Building
--------

First, obtain a copy of this repository and its dependencies:

    git clone --recursive https://github.com/tniessen/iperf-windows

Open `iperf.sln` in Visual Studio and choose "Debug" or "Test Release"
as the build mode.

If the submodule `iperf` does not contain `src/iperf_config.h` and
`src/version.h`, you will need to add these files based on available templates
templates (`*.in`).

License
-------

Copyright (C) 2015 Heise Zeitschriften Verlag GmbH & Co. KG

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
