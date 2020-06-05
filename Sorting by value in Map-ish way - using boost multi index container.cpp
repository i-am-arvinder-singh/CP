#include <boost/multi_index_container.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <iostream>

struct key_tag {};
struct value_tag {};

typedef std::pair< double, double > element_t;

typedef boost::multi_index_container<
    element_t,
    boost::multi_index::indexed_by<
      boost::multi_index::ordered_unique< boost::multi_index::tag< key_tag >,
          boost::multi_index::member< element_t, double, &element_t::first > >,
      boost::multi_index::ordered_unique< boost::multi_index::tag< value_tag >,
          boost::multi_index::member< element_t, double, &element_t::second > >
> >  dataset_t;

typedef dataset_t::index<key_tag>::type  key_index_t;
typedef dataset_t::index<value_tag>::type value_index_t;

int main()
{
    dataset_t data;

    data.insert( element_t( 3.14, 42.0 ) );
    data.insert( element_t( 10.01, 12.16 ) );
    data.insert( element_t( 14.62, 53.16 ) );
    data.insert( element_t( 16.33, 4.16 ) );
    data.insert( element_t( 45.23, 100.23 ) );
    data.insert( element_t( 0.23, 34.09 ) );

     std::cout << "Data sorted by key field:" << std::endl;
     key_index_t& kindex = data.get<key_tag>();
     for( key_index_t::iterator k = kindex.begin(); k != kindex.end(); ++k )
        std::cout << k->first << " ==> " << k->second << std::endl;

     std::cout << "Data sorted by value field:" << std::endl;
     value_index_t& vindex = data.get<value_tag>();
     for( value_index_t::iterator v = vindex.begin(); v != vindex.end(); ++v )
        std::cout << v->first << " ==> " << v->second << std::endl;
}