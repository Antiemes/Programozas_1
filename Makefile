TEX = pdflatex -interaction nonstopmode
BIB = bibtex
DOCKERIMAGE = antiemes/latex


MAINDOCUMENT = thesis
BIBFILE = references.bib
FIGURES = $(shell find *.eps *.png *.jpg)

#all: $(MAINDOCUMENT).tex $(MAINDOCUMENT).bbl $(FIGURES)
all: $(MAINDOCUMENT).tex $(FIGURES)
	$(TEX) $(MAINDOCUMENT)
	$(TEX) $(MAINDOCUMENT)
	convert -density 300 cover.pdf -quality 98 cover_as_img.pdf
	pdftk $(MAINDOCUMENT).pdf cat 2-end output $(MAINDOCUMENT)-2-.pdf
	pdftk cover_as_img.pdf $(MAINDOCUMENT)-2-.pdf cat output $(MAINDOCUMENT)-with-cover.pdf

spell::
	ispell *.tex

clean::
	rm -fv *.aux *.log *.bbl *.blg *.toc *.out *.lot *.lof *.loa $(MAINDOCUMENT).pdf *-converted-to.pdf

$(MAINDOCUMENT).bbl: $(MAINDOCUMENT).tex $(BIBFILE)
	$(TEX) $(MAINDOCUMENT)
	$(BIB) $(MAINDOCUMENT)

docker-all::
	docker run --rm -v ${PWD}:/project -w /project $(DOCKERIMAGE)  make all
