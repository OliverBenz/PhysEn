# Build project
## Dependencies
- Google tests will automatically be pulled by CMake. 
- Generating the documentation requires you to have `doxygen` installed. (See [documentation](documentation.md))

# Pull and Build
- `git clone https://github.com/OliverBenz/PhysEn.git`
- `cd PhysEn`
- `mkdir build; cd build`
- `cmake ..`
- `make`

When generating the build solution using `cmake ..`, the _Debug_ or _Release_ build can be specified using by using
`cmake -DCMAKE_BUILD_TYPE=[Debug|Release] ..`
.

After building the project, the library can be installed system-wide by running `cmake --install .` from inside the _build_ folder.

## Testing and Examples
Ater the build step, along with the physen library, there are unit tests and examples available.
 

The **tests** can be run by executing:
- `./tests/tests` inside the `build/` directory.

The **examples** can be run by executing:
- `./examples/[NAME]` inside the `build/` directory.
  (Example`./examples/rocket`)