int uadd_ok(unsigned x, unsigned y)
{
  unsigned s = x + y;
  if(s < x || s < y)
    return 0;
  else
    return 1;
}

int tadd_ok(int x, int y)
{
  int s = x + y;
  if(x > 0 && y > 0 && s <= 0)
    return 0;
  if(x < 0 && y < 0 && s >= 0)
    return 0;
  return 1;
}

int main(int argc, char* argv[])
{
  return 0;
}
