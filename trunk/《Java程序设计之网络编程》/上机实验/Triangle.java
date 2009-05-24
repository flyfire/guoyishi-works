class Point {
	private double x, y;
	public Point() {
		x = 0.0;
		y = 0.0;
	}
	
	public Point (double x, double y) {
		this.x = x;
		this.y = y;
	}
	
	public double getX() {
		return x;
	}
	
	public double getY() {
		return y;
	}
	
	public void setX(double x) {
		this.x = x;
	}
	
	public void setY(double y) {
		this.y = y;
	}
	
	public void setXY(double x, double y) {
		this.x = x;
		this.y = y;
	}
}

class Line {
	private Point a, b;
	private double length;
	public Line() {
		length = 0.0;
	}
	
	public Line(Point a, Point b) {
		this.a = a;
		this.b = b;
	}
	
	public void setLine(Point a, Point b) {
		this.a = a;
		this.b = b;
	}
	
	public double value() {
		double v1 = (a.getX() - b.getX()) * (a.getX() - b.getX());
		double v2 = (a.getY() - b.getY()) * (a.getY() - b.getY());
		length = Math.sqrt(v1 + v2);
		return length;
	}
}

class Triangle {
	
	private Point a, b, c;
	private Line line1, line2, line3;
	public Triangle() {
		a.setXY(0.0, 0.0);
		b.setXY(0.0, 0.0);
		c.setXY(0.0, 0.0);
	}
	
	public Triangle(Point a, Point b, Point c) {
		this.a = a;
		this.b = b;
		this.c = c;
	}
	
	public double area() {
		line1.setLine(a, b);
		line2.setLine(b, c);
		line3.setLine(a, c);
		double p;
		double len1 = line1.value();
		double len2 = line2.value();
		double len3 = line3.value();
		p = (len1 + len2 + len3) / 2;
		double s;
		s = Math.sqrt(p * (p - len1) * (p - len2) * (p - len3));
		
		return s;
	}
	
	public double perimeter() {
		line1.setLine(a, b);
		line2.setLine(b, c);
		line3.setLine(a, c);
		double length;
		length = line1.value() + line2.value() + line3.value();
		
		return length;
	}
	public static void main(String args[]){
		Point p1 = new Point(0.0, 0.0);
		Point p2 = new Point(1.0, 1.0);
		Point p3 = new Point(1.0, 0.0);
		Triangle tri1 = new Triangle(p1, p2, p3);
		System.out.println("Area:" + tri1.area());
		System.out.println("Perimeter:" + tri1.perimeter());
	}
}