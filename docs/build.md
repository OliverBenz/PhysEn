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

After building the project, the library can be installed system-wide by running `cmake --install .` from inside the _build_ folder.

## Testing and Examples
After compiling.

The **tests** can be run by executing:
- `./tests/tests` inside the `build/` directory.

The **examples** can be run by executing:
- `./examples/[NAME]` inside the `build/` directory.
  (Example`./examples/rocket`)