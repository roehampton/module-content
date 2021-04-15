var links = document.links;

for (var i = 0, linksLength = links.length; i < linksLength; i++) {
    links[i].target = '_blank';
}