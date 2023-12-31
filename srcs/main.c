/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 17:10:08 by eros-gir          #+#    #+#             */
/*   Updated: 2023/09/27 22:33:12 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cube.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (cb_validate_args(argc) || cb_validate_map_extension(argv[1]))
		return (1);
	game.file = argv[1];
	if (cb_parser(&game))
		return (1);
	cb_setup(&game);
	mlx_hook(game.mlx.win_ptr, 2, 0, &cb_keydown, &game);
	mlx_hook(game.mlx.win_ptr, 17, 0, &cb_destroy, &game);
	mlx_loop_hook(game.mlx.mlx_ptr, cb_render, &game);
	mlx_loop(game.mlx.mlx_ptr);
	return (0);
}
