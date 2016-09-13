// Boost.Geometry (aka GGL, Generic Geometry Library)

// Copyright (c) 2016 Oracle and/or its affiliates.
// Contributed and/or modified by Vissarion Fisikopoulos, on behalf of Oracle

// Use, modification and distribution is subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_GEOMETRY_STRATEGIES_CARTESIAN_AZIMUTH_CARTESIAN_HPP
#define BOOST_GEOMETRY_STRATEGIES_CARTESIAN_AZIMUTH_CARTESIAN_HPP

#include <boost/geometry/core/tags.hpp>

namespace boost { namespace geometry
{

namespace strategy { namespace azimuth
{

template
<
    typename CalculationType
>
class azimuth_cartesian
{
public :

    inline azimuth_cartesian()
    {}

    inline void apply(CalculationType const& lon1_rad,
                      CalculationType const& lat1_rad,
                      CalculationType const& lon2_rad,
                      CalculationType const& lat2_rad,
                      CalculationType& a1,
                      CalculationType& a2) const
    {
        // not implemented
    }

};

#ifndef DOXYGEN_NO_STRATEGY_SPECIALIZATIONS

namespace services
{

template <typename CalculationType>
struct default_strategy<cartesian_tag, CalculationType>
{
    typedef strategy::azimuth::azimuth_cartesian<CalculationType> type;
};

}

#endif // DOXYGEN_NO_STRATEGY_SPECIALIZATIONS

}} // namespace strategy::azimuth


}} // namespace boost::geometry

#endif // BOOST_GEOMETRY_STRATEGIES_CARTESIAN_AZIMUTH_CARTESIAN_HPP
