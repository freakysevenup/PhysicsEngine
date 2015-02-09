#pragma once
#include <math.h>

class PhysicsEngine
{
public:
	struct Matrix3x3;

#pragma region Vector2

	struct Vector2
	{
	public:

		Vector2(void);
		Vector2(float, float);
		Vector2(Vector2, Vector2);
		~Vector2(void);

		Vector2 operator + (Vector2);
		Vector2 operator += (Vector2);
		Vector2 operator + (float);
		Vector2 operator += (float);
		Vector2 operator - (Vector2);
		Vector2 operator -= (Vector2);
		Vector2 operator * (Vector2);
		Vector2 operator *= (Vector2);
		Vector2 operator * (float);
		Vector2 operator *= (float);
		Vector2 operator / (float);

		bool operator == (Vector2);
		bool operator != (Vector2);
		bool operator < (Vector2);
		bool operator > (Vector2);

		Vector2 Zero();
		Vector2 Normalize();
		float Dot(PhysicsEngine::Vector2, PhysicsEngine::Vector2);

		void rotateVector(float);
		float Length();

		float x, y;
	};

#pragma endregion

#pragma region Vector3

	struct Vector3
	{
	public:
		public:

		Vector3(void);
		Vector3(float, float, float);
		Vector3(Vector3, Vector3);
		~Vector3(void);

		Vector3 operator + (Vector3);
		Vector3 operator += (Vector3);
		Vector3 operator + (float);
		Vector3 operator += (float);
		Vector3 operator - (Vector3);
		Vector3 operator -= (Vector3);
		Vector3 operator * (Vector3);
		Vector3 operator *= (Vector3);
		Vector3 operator * (float);
		Vector3 operator *= (float);
		Vector3 operator * (Matrix3x3);
		Vector3 operator / (float);
		Vector3 operator /= (float);

		bool operator == (Vector3);
		bool operator != (Vector3);
		bool operator < (Vector3);
		bool operator > (Vector3);
		
		Vector3 Zero();
		Vector3 Normalize();
		Vector3 Cross(Vector3);
		float Length();
		float Dot(Vector3, Vector3);

		float x, y, z;
	};


#pragma endregion

#pragma region Vector4


struct Vector4
	{
		public:

		Vector4(void);
		Vector4(float xx, float yy, float zz, float ww);
		~Vector4(void);

		void operator () (float xx, float yy, float zz, float ww);
		bool operator == (Vector4 &param);
		bool operator != (Vector4 &param);
		Vector4 operator = (Vector4 &param);
		Vector4 operator - (void);
		Vector4 operator + (Vector4 &param);
		Vector4 operator - (Vector4 &param);
		Vector4 operator * (float param);
		Vector4 operator / (float param);
		Vector4 operator += (Vector4 &param);
		Vector4 operator -= (Vector4 &param);
		Vector4 operator *= (float param);
		Vector4 operator /= (float param);
		float operator * (Vector4 &param);
		Vector4 operator % (Vector4 &param);

		float Length_Squared();
		float Length();
		void Normalize();
		void Reflect(Vector4 &param);
		void Project(Vector4 &param);
		Vector4 Projected(Vector4 &param);

		float x, y, z, w;
	};

#pragma endregion

#pragma region Matrix3x3

	struct Matrix3x3
	{
	public:
		Matrix3x3(void);

		// A1 A2 A3
		// B1 B2 B3
		// C1 C2 C3
		Matrix3x3(float a_One, float a_Two, float a_Three, float b_One, float b_Two, float b_Three, float c_One, float c_Two, float c_Three);
		Matrix3x3(Vector3, Vector3, Vector3);
		~Matrix3x3(void);

		Matrix3x3 operator + (Matrix3x3);
		Matrix3x3 operator += (Matrix3x3);
		Matrix3x3 operator - (Matrix3x3);
		Matrix3x3 operator -= (Matrix3x3);
		Matrix3x3 operator * (Matrix3x3);
		Matrix3x3 operator *= (Matrix3x3);
		Matrix3x3 operator * (float);
		Matrix3x3 operator *= (float);
		Matrix3x3 operator / (float);
		Matrix3x3 operator /= (float);

		bool operator == (Matrix3x3);
		bool operator != (Matrix3x3);

		Matrix3x3 InvertMatrix();
		Matrix3x3 TransposeMatrix();
		Matrix3x3 GetAdjunct();
		Matrix3x3 RotateMatrix(float angle, char axis);
		float Get3x3Determinant(float, float, float, float, float, float);

		float I11, I12, I13, I21, I22, I23, I31, I32, I33;
		float D11, D12, D13, D21, D22, D23, D31, D32, D33;
	};

#pragma endregion

#pragma region Matrix4x4

struct Matrix4x4
	{
	public:
		Matrix4x4(void);

		// A1 A2 A3 A4
		// B1 B2 B3 B4
		// C1 C2 C3 C4
		// D1 D2 D3 D4
		Matrix4x4(float a_One, float a_Two, float a_Three, float a_Four, 
			float b_One, float b_Two, float b_Three, float b_Four, 
			float c_One, float c_Two, float c_Three, float c_Four, 
			float d_One, float d_Two, float d_Three, float d_Four);
		Matrix4x4(Vector4, Vector4, Vector4, Vector4);
		~Matrix4x4(void);

		Matrix4x4 operator + (Matrix4x4);
		Matrix4x4 operator += (Matrix4x4);
		Matrix4x4 operator - (Matrix4x4);
		Matrix4x4 operator -= (Matrix4x4);
		Matrix4x4 operator * (Matrix4x4);
		Matrix4x4 operator *= (Matrix4x4);
		Matrix4x4 operator * (float);
		Matrix4x4 operator *= (float);
		Matrix4x4 operator / (float);
		Matrix4x4 operator /= (float);

		bool operator == (Matrix4x4);
		bool operator != (Matrix4x4);

		Matrix4x4 InvertMatrix();
		Matrix4x4 TransposeMatrix();
		Matrix4x4 GetAdjunct();
		Matrix4x4 RotateMatrix(float angle, char axis);
		float Get3x3Determinant(float, float, float, float, float, float);

		float I11, I12, I13, I14, I21, I22, I23, I24, I31, I32, I33, I34, I41, I42, I43, I44;
		float D11, D12, D13, D14, D21, D22, D23, D24, D31, D32, D33, D34, D41, D42, D43, D44;
	};

#pragma endregion

#pragma region Quaternion

	struct Quaternion
	{
	public:
		Quaternion(void);

		Quaternion(float _w, Vector3 _v);
		Quaternion(Vector4 _v);
		Quaternion(float _w, float _x, float _y, float _z);
		~Quaternion(void);

		void QuaternionFromEulerAngles(float theta_z, float theta_y, float theta_x);
		void QuaternionFromEulerAngles(const PhysicsEngine::Vector3 &angles);

		Quaternion operator = (Quaternion);	
		Quaternion operator + (Quaternion);
		Quaternion operator - (Quaternion);	
		Quaternion operator * (Quaternion);	
		Quaternion operator / (Quaternion);	
		Quaternion operator * (float);
		Quaternion operator / (float);
		Quaternion operator - ();
		Quaternion operator += (Quaternion);	
		Quaternion operator -= (Quaternion);		
		Quaternion operator *= (Quaternion);	
		Quaternion operator *= (float);
		Quaternion operator /= (float);

	
		float Length();
		float Length_Squared();
		void Normalize();
		Quaternion Normalized();
		void Conjugate();
		void Invert();
		Quaternion Log();
		Quaternion Exp();
		static inline float Dot(PhysicsEngine::Quaternion q1, PhysicsEngine::Quaternion q2);
		static Quaternion Lerp(PhysicsEngine::Quaternion q1, PhysicsEngine::Quaternion q2, float t);
		static Quaternion Slerp(PhysicsEngine::Quaternion q1, PhysicsEngine::Quaternion q2, float t);
		static Quaternion SlerpNoInvert(PhysicsEngine::Quaternion q1, PhysicsEngine::Quaternion q2, float t);
		static Quaternion Squad(Quaternion q1, Quaternion q2, Quaternion a, Quaternion b, float t);
		static Quaternion Bezier(Quaternion q1, Quaternion q2, Quaternion a, Quaternion b, float t);
		static Quaternion Spline(Quaternion qnm1, Quaternion qn, Quaternion qnp1);
		static inline Quaternion From_Axis_Angle(Vector3 axis, float angle);
		void To_Axis_Angle(Vector3 axis, float angle);
		Vector3 Rotate(PhysicsEngine::Vector3 v);
		Vector3 Euler_Angles(bool homogenous = true);

		Vector3 v;
		float s;
	};

#pragma endregion

};