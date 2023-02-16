namespace FBCE {
	class Vec2 {
		public:
			float x;
			float y;
			static Vec2 Rotate(Vec2 _pos, float _angle) {
				return Vec2(_pos.x*cos(_angle)-_pos.y*sin(_angle),_pos.y*cos(_angle)-_pos.x*sin(_angle));
			}
			static Vec2 Rotate(Vec2 _pos, Vec2 _origin, float _angle) {
				Vec2 localcoor = Vec2(_pos.x-_origin.x, _pos.y-_origin.y);
				Vec2 pp = Rotate(pp, _angle);
				return Vec2(pp.x + _origin.x, pp.y + _origin.y);
			}
			Vec2() : x(0), y(0) {}
			Vec2(float _x, float _y) : x(_x), y(_y) {}
	};
}
