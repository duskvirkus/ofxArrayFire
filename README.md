# ofxArrayFire

An openFrameworks addon with pre-compiled binaries of [ArrayFire](https://github.com/arrayfire/arrayfire).

ArrayFire is a general-purpose library that simplifies the process of developing software that targets parallel and massively-parallel architectures including CPUs, GPUs, and other hardware acceleration devices.

Currently this addon only supports **Windows 10 with with Visual Studio**.

ArrayFire Version: 3.8.0 (Windows)

Tested with: of_v0.11.2_vs2017_release

**Important Notice:** Neither ArrayFire nor any of its contributors were involved in the creation of this addon. Please see the project licence for more information on the use of ArrayFire.

## Installation

```bash
# in <of_root>/addons
git clone https://github.com/duskvirkus/ofxArrayFire
```

## Usage

### Target Accelerator

**Important:** Currently setup to only target **cpu OR cuda OR opencl** when generating projects. Please change `addon_config.mk` before using project generator to create or update an openframeworks project. The file is setup to use the cuda version out of the box.

Keep in mind that you can always change `addon_config.mk` to target another accelerator type however update an existing project with `addon_config.mk` set to a different accelerator will result in undefined behavior.

### Creating New Projects

Once the target is set by including the correct library in `addon_config.mk` use project generator as you would normally.

`#include <ofxArrayFire.h>` to include ArrayFire in your project this includes all the ArrayFire headers. The library uses the namespace `af::`.

## Examples

Take a look at the few examples to see how you might use ArrayFire with openFrameworks.

See all ArrayFire examples visit: https://github.com/arrayfire/arrayfire/tree/master/examples

## Documentation

Check out the ArrayFire Documentation: https://arrayfire.org/docs/

## Contributing

Support for additional operating systems and converting more ArrayFire examples is welcome and pull requests will likely be accepted. For other modifications or improvements I suggest opening an issue to discuss the change.
