#include	<vector>
#include	<iterator>
#include	<cmath>
#include	"Graph.hh"
#include	"Core.hh"
#include	"Errur.hh"
#include	"Parser.hh"

#include	"Vector2ic.hh"

int	main(int ac, char **av)
{
  std::vector<int>	vec;
  try
    {
      // Parser *parser = new Parser();
      // vec = parser->parse(" sgt 0 1 2 3 4 5 6");

      // for(std::vector<int>::iterator i = vec.begin(); i != vec.end();++i)
      // 	std::cout << *i << std::endl;


      // Graph *graph = new Graph(1440, 900, 20, 20);
      // graph->run();

      Core      core(ac, av);
      core.go();

      // for (int i = 1; i < 100; i++)
      // 	{
      // 	  std::cout << (log(i) + 4) / 5 << std::endl;
      // 	}
    }
  catch (Errur* e)
    {
      std::cout << e->what() << std::endl;
    }
  return (0);
}
