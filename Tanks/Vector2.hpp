#pragma once

#ifndef VECTOR2_HPP
#define VECTOR2_HPP

namespace Engine
{
	struct Vector2
	{
		/* =============================================================
		* PUBLIC FUNCTIONS
		* ============================================================= */
		explicit Vector2();
		explicit Vector2(float x, float y);
		Vector2(const Vector2& other);

		float Normalize();
		float CalcLength();
		float CalcLengthSquared();
		void Scale(float scaleUnit);
		float SetLength(float newLength);
		float DotProduct(const Vector2& rhs);
		float Cross(const Vector2& rhs);
		void SetXY(float _x, float _y);

		/* =============================================================
		* OPERATOR OVERLOADS
		* ============================================================= */
		Vector2& operator=			(const Vector2& rhs);
		Vector2& operator+=			(const Vector2& rhs);
		Vector2& operator-=			(const Vector2& rhs);
		Vector2& operator*=			(const Vector2& rhs);
		Vector2& operator/=			(const Vector2& rhs);
		Vector2 operator+			(const Vector2& rhs);
		Vector2 operator-			(const Vector2& rhs);
		Vector2 operator-			();
		Vector2 operator*			(const Vector2& rhs);
		Vector2 operator/			(const Vector2& rhs);
		bool operator==				(const Vector2& rhs);
		bool operator!=				(const Vector2& rhs);

		/* =============================================================
		* FRIENDS
		* ============================================================= */
		friend Vector2 operator*	(float scaleUnit, const Vector2& rhs);
		friend Vector2 operator*	(const Vector2& lhs, float scaleUnit);

		/* =============================================================
		* STATIC FUNCTIONS
		* ============================================================= */
		static float DotProduct(const Vector2& lhs, const Vector2& rhs);
		static float CrossProduct(const Vector2& lhs, const Vector2& rhs);

		/* =============================================================
		* MEMBERS
		* ============================================================= */
		float						x;
		float						y;
		float						length;
	};
}

#endif // !VECTOR2_HPP