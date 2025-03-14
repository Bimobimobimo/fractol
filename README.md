# Fractol
## Description
Fractol is a graphical program that generates and visualizes fractals using the MiniLibX library. The project focuses on rendering the Mandelbrot and Julia sets, with interactive controls for zooming, panning, and parameter customization.

### Features
- Mandelbrot Set: Display and navigate the Mandelbrot fractal.
- Julia Set: Generate different Julia fractals using command-line parameters.
- Infinite Zoom: Smooth and precise zooming using the mouse wheel.
- Color Effects: Apply colors to enhance fractal depth and create psychedelic effects.

### Window Management:
Close the window properly using the ESC key or the close button.
Smooth window handling (minimization, resizing, etc.).
Keyboard Controls (Bonus): Move the fractal view using arrow keys.

## Installation
Compile the program with:

```sh
make
```
This will generate the fractol executable.

## Usage
Run the program with a fractal type as an argument:

```sh
./fractol mandelbrot
```
For Julia sets, you can specify additional parameters:

```sh
./fractol julia 0.285 0.01
```
If an invalid argument is provided, the program will display a help message listing available options.

## Controls
- Mouse Wheel: Zoom in/out.
- Arrow Keys: Move the fractal view (if implemented as a bonus).
- ESC: Close the window and exit the program.
- Close Button: Properly terminates the program.

## Dependencies
MiniLibX: Required for rendering graphics. Make sure it is installed before compiling.
