# FdF

This project is about creating a simplified graphic “wireframe” (“fils de fer” in french, hence the name of the project) representation of a relief landscape linking various points (x, y, z) via segments. 
The coordinates of this landscape are stored in a file passed as a parameter to your program. 

<p align="center">
  <img src="/images/fdf.png" width="100%" alt="fdf"/>
</p>

### How to install

```
git clone https://github.com/kagestonedragon/fdf.git ~/fdf
```

2) Compile
```
make -C ~/fdf
```

### How to use

```
./fdf <maps>
```
Run FdF with parameters:
* `<map>` — input map (in text format)

Some maps you can find in `/maps` directory.

### How it works

* `mlx lib` — library that can create a window and put 1 pixel on the screen
* `bresenham's line algorithm` — line drawing algorithm that determines the points of an n-dimensional raster that should be selected in order to form a close approximation to a straight line between two points.
* `rotation matrix` —  is a matrix that is used to perform a rotation in Euclidean space.
* `projection matrix` — (in linear algebra and functional analysis, a projection is a linear transformation from a vector space to itself such that.)
* `other things`

#### Input file:

```
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0 
```
#### Result:

<p align="center">
  <img src="/images/result.gif" width="100%" alt="fdf"/>
</p>

