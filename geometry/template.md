[top](../README.md)

# [幾何テンプレート](./template.hpp)

## Inequality

`bool almostEqual(long double a, long double b)` 

`bool lessThan(long double a, long double b)`

`bool greaterThan(long double a, long double b)`

`bool lessThanOrEqual(long double a, long double b)`

`bool greaterThanOrEqual(long double a, long double b)`
- EPSを用いた不等式評価

## Structure

### Point

`Point(long double x, long double y)`
- 二次元平面状の位置ベクトル $(x, y)$

`Point::dot(Point p)`
- $p$ との内積を返す。

`Point::cross(Point p)`
- $p$ との外積を返す。

`Point::cross(Point p1, Point p2)`
- $p1$ と $p2$ を端点とするベクトルとの外積を返す。

`Point::norm()`
- ベクトルの長さの二乗を返す。

`Point::abs()`
- ベクトルの長さを返す。

`Point::arg()`
- ベクトルの偏角を返す。



### Segment

`Segment(Point a, Point b)`

`Segment(long double A, long double B, long double C)`
- 線分

### Line

`Line(Point a, Point b)`

`Line(long double A, long double B, long double C)`
- 直線

(一般には==が壊れるので注意)

### Circle

`Circle(long double x, long double y, long double r)`

`Circle(Point _center, long double r)`
- 円

## Point and Vector

### Counter Clockwise

`Orientation ccw(Point p0, Point p1, Point p2)`
- 点の進行方向

```cpp
enum Orientation {
    COUNTER_CLOCKWISE,
    CLOCKWISE,
    ONLINE_BACK,
    ONLINE_FRONT,
    ON_SEGMENT
};
```

### 射影

`Point projection(Point p1, Point p2, Point p)`

`Point projection(Line l, Point p)`


### 反射

`Point reflection(Point p1, Point p2, Point p)`

`Point reflection(Line l, Point p)`

## Segment and Line

### 平行判定

`bool isParallel(Line(Segment) l1, Line(Segment) l2)`

### 垂直判定

`bool isOrthogonal(Line(Segment) l1, Line(Segment) l2)`

---

### 直線上に点が存在するか判定

`bool isPointOnLine(Point p, Line l)`

### 線分上に点が存在するか判定

`bool isPointOnSegment(Point p, Line l)`

### 線分と線分の交差

`bool isIntersecting(Segment s1, Segment s2)`

### 線分と線分の交点

`Point getIntersection(Segment s1, Segment s2)`

--- 

### 点と直線の距離

`long double distancePointToSegment(Point p, Segment s)`

### 線分と線分の距離

`long double distanceSegmentToSegment(Segment s1, Segment s2)`

## Polygon

### 多角形の面積

`long double getPolygonArea(vector<Point> points)`

---

### 凸多角形の判定

`bool isConvex(vector<Point> points)`

---

### 点が凸多角形の辺上に存在するか判定

`bool isPointOnPolygon(vector<Point> polygon, Point p)`

### 点が凸多角形の内部に存在するか判定

`bool isPointInsidePolygon(vector<Point> polygon, Point p)`
- たまに↑を包含

## Convex Polygon

### 凸包

`vector<Point> convexHull(vector<Point> points, bool include_collinear = false)`

---

### 凸包の直径

`long double convexHullDiameter(vector<Point> hull)`

---

### 凸包をカットして左側を返す

`vector<Point> cutPolygon(vector<Point> g, Point p1, Point p2)`

## Point Set

### 最近点対

`long double closestPair(vector<Point> points, int l, int r)`
- x座標の値でソートされた点列を渡す

## Segment Set

### 線分集合の交点の個数

`int countIntersections(vector<Segment> segments)`

## Circle

### 2つの円の交点の個数

`int countCirclesIntersection(Circle c1, Circle c2)`

---

### 内接円

`Circle getInCircle(Point A, Point B, Point C)`

---

### 外接円

`Circle getCircumCircle(Point A, Point B, Point C)`

---

### 円と直線の交点

`vector<Point> getCircleLineIntersection(Circle c, Point p1, Point p2)`

### 2つの円の交点

`vector<Point> getCirclesIntersect(Circle c1, Circle c2)`

### 点 $p$ を通る接線との接点

`vector<Point> getTangentLinesFromPoint(Circle c, Point p)`

### 2つの円の共通接線

`vector<Segment> getCommonTangentsLine(Circle c1, Circle c2)`
