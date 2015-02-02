void createFile() {
  START;
  FILE* ff;
  ff = fopen("test.dat","wb");
  int* dane = new int[SZ];
  REP(i,SZ) dane[i] = i;
  fwrite(dane, 4, SZ, ff);
  fclose(ff);
  ff = fopen("test.dat","rb");
  int odczytane[10];
  fseek(ff,120,SEEK_SET);
  fread(odczytane, 4, 10, ff);    //dest*, #bytes_each, #objects, file*)
  fclose(ff);
  STOP(" --> czas zapisu");
}

void randomReadFile() {
  srand(111);
  ll controlSum = 0;
  FILE* ff;
  ff = fopen("test.dat","rb");
  START;
  REP(i,RD_CNT) {
    int which = rand() % SZ;
    int dst = 0;
    fseek(ff, which*4, SEEK_SET);
    fread(&dst, 4, 1, ff);
    controlSum = (controlSum + dst) % 10007;
  }
  STOP(" --> czas odczytu(dysk)");
  cout << "(control sum:" << controlSum << ")\n";
}
