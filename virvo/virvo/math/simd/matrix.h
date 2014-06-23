#ifndef VV_SIMD_MATRIX_H
#define VV_SIMD_MATRIX_H


#include "vec.h"

#include <ostream>

namespace virvo
{

namespace math
{


template < >
class matrix< 4, 4, simd::float4 >
{
public:

    typedef simd::float4 column_type;

    column_type col0;
    column_type col1;
    column_type col2;
    column_type col3;


    matrix();
    matrix(column_type const& c0,
           column_type const& c1,
           column_type const& c2,
           column_type const& c3);

    explicit matrix(float const data[16]);

    column_type& operator()(size_t col);
    column_type const& operator()(size_t col) const;

};


//-------------------------------------------------------------------------------------------------
// Free function declarations
//

matrix< 4, 4, simd::float4 > operator*(matrix< 4, 4, simd::float4 > const& a,
    matrix< 4, 4, simd::float4 > const& b);

vector< 4, simd::float4 > operator*(matrix< 4, 4, simd::float4 > const& m,
    vector< 4, simd::float4 > const& v);

matrix< 4, 4, simd::float4 > transpose(matrix< 4, 4, simd::float4 > const& m);


} // math

} // virvo


#include "../detail/simd/matrix4.inl"


#endif // VV_SIMD_MATRIX_H

