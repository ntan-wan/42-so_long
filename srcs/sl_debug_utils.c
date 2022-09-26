int ft_printf(const char *str, ...);

/* print keypress keycode */
int sl_debug_keycode_keypress(int keycode)
{
    ft_printf("keycode -> %d\n", keycode);
    return (0);
}

/* handle no event */
int sl_debug_loop(void)
{
    return (0);
}