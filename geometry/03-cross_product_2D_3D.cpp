//Cross product (3D points)
point3d cross(point3d a, point3d b) {
    return point3d(a.y * b.z - a.z * b.y,
                   a.z * b.x - a.x * b.z,
                   a.x * b.y - a.y * b.x);
}
ftype triple(point3d a, point3d b, point3d c) {
    return dot(a, cross(b, c));
}

//Cross product (2D points)
ftype cross(point2d a, point2d b) {
    return a.x * b.y - a.y * b.x;
}