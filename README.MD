# Raytracer

This project is my reimplementation of the [Raytracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html) course.

**Table Of Contents.**
- [Build](#compile--run)
- [Usage](#usage)
- [Links](#links)

## Build

This project was developed and tested unter the *Windos-Subsystem for Linux* ([wsl](https://learn.microsoft.com/en-us/windows/wsl/about)).

Building the project requires a `c++` compiler and`make`. These dependencies can be installed as follows:

```
# apt install build-essential
```

The project can then be build as follows:

```
$ make
```

## Usage

To run the raytracer and store the result as `image.ppm`, issue the following command:
```
$ raytracer > image.ppm
```

The result is stored as a [Portable Pixelmap (PPM)](https://de.wikipedia.org/wiki/Portable_Anymap#Pixmap).

## Links

- Original project [github](https://github.com/petershirley/raytracinginoneweekend)
- Original project [homepage](https://in1weekend.blogspot.com/)