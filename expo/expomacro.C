void expomacro()
{
TH1F *h= new TH1F("h", " exponential ", 12, 0,120);
FILE *f= fopen("exdat.dat", "r");
float data ;
int i = 0;
while (!feof(f))
{
	fscanf(f, "%f", &data);
        ++i;
	h-> SetBinContent(i, data);
	//h->Fill(data);
	
}
fclose(f);
h->Fit("expo");
h->GetXaxis()->SetTitle("Value");
h->GetYaxis()->SetTitle("Value");
h->Draw();
}
