#include "iu_scene.h"

int parse_int(const char **str) {
    int num = 0, sign = 1;
    if (**str == '-') { sign = -1; (*str)++; }
    while (**str >= '0' && **str <= '9') {
        num = num * 10 + (**str - '0');
        (*str)++;
    }
    return num * sign;
}

float parse_float(const char **str) {
    float result = 0.0;
    float factor = 1.0;
    int sign = 1;
    
    if (**str == '-') { sign = -1; (*str)++; }
    
    // Parse integer part
    while (**str >= '0' && **str <= '9') {
        result = result * 10.0 + (**str - '0');
        (*str)++;
    }
    
    // Parse fractional part
    if (**str == '.') {
        (*str)++;
        while (**str >= '0' && **str <= '9') {
            result = result + (**str - '0') * (factor *= 0.1f);
            (*str)++;
        }
    }
    
    return result * sign;
}

void skip_spaces(const char **str) {
    while (**str == ' ' || **str == '\t') (*str)++;
}

void parse_color(const char **str, t_color *color, t_scene *scene) {
    color->r = parse_int(str);
    if (color->r < 0 || color->r > 255) 
        ft_error("Color R out of range [0, 255]", &scene->data, EXIT_FAILURE);
    (*str)++; // skip comma
    color->g = parse_int(str);
    if (color->g < 0 || color->g > 255)
        ft_error("Color G out of range [0, 255]", &scene->data, EXIT_FAILURE);
    (*str)++; // skip comma
    color->b = parse_int(str);
    if (color->b < 0 || color->b > 255)
        ft_error("Color B out of range [0, 255]", &scene->data, EXIT_FAILURE);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!d && !s)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

void *ft_realloc(void *ptr, size_t size) {
    if (size == 0) {
        free(ptr);
        return NULL;
    }

    if (ptr == NULL) {
        return malloc(size);
    }

    void *new_ptr = malloc(size);
    if (new_ptr == NULL) {
        return NULL;
    }

    // Copy the old data to the new memory block
    memcpy(new_ptr, ptr, size);
    free(ptr);

    return new_ptr;
}
