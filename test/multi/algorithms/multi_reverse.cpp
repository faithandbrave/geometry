// Boost.Geometry (aka GGL, Generic Geometry Library)
//
// Copyright Barend Gehrels, Geodan B.V. Amsterdam, the Netherlands.
// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include <geometry_test_common.hpp>

#include <boost/geometry/algorithms/reverse.hpp>
#include <boost/geometry/multi/algorithms/reverse.hpp>

#include <boost/geometry/extensions/gis/io/wkt/wkt.hpp>

#include <boost/geometry/geometries/geometries.hpp>

#include <boost/geometry/multi/geometries/multi_point.hpp>
#include <boost/geometry/multi/geometries/multi_linestring.hpp>
#include <boost/geometry/multi/geometries/multi_polygon.hpp>

#include <algorithms/test_reverse.hpp>


template <typename P>
void test_all()
{
	// Multi point, should happen nothing.
    test_geometry<boost::geometry::multi_point<P> >(
        "MULTIPOINT((0 0),(1 1))",
        "MULTIPOINT((0 0),(1 1))");

    test_geometry<boost::geometry::multi_linestring<boost::geometry::linestring<P> > >(
        "MULTILINESTRING((0 0,1 1),(3 3,4 4))",
        "MULTILINESTRING((1 1,0 0),(4 4,3 3))");

    typedef boost::geometry::multi_polygon<boost::geometry::polygon<P> > mp;
    test_geometry<mp>(
        "MULTIPOLYGON(((4 0,8 2,8 7,4 9,0 7,0 2,2 1,4 0)))",
        "MULTIPOLYGON(((4 0,2 1,0 2,0 7,4 9,8 7,8 2,4 0)))");
    test_geometry<mp>(
        "MULTIPOLYGON(((4 0,8 2,8 7,4 9,0 7,0 2,2 1,4 0),(7 3,7 6,1 6,1 3,4 3,7 3)))",
        "MULTIPOLYGON(((4 0,2 1,0 2,0 7,4 9,8 7,8 2,4 0),(7 3,4 3,1 3,1 6,7 6,7 3)))");
}

int test_main( int , char* [] )
{
    test_all<boost::geometry::point_xy<int> >();
    test_all<boost::geometry::point_xy<double> >();

    return 0;
}
