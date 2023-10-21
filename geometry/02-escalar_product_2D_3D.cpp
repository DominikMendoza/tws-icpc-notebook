//Scalar product (2D points)
ftype dot(point2d a, point2d b) {
    return a.x * b.x + a.y * b.y;
}
//Scalar product (3D points)
ftype dot(point3d a, point3d b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}