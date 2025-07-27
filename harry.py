import urllib.request,urllib.parse
import json
# Liste des animes valides
api_url = "https://potterapi-fedeperin.vercel.app/en/books?"
nom_personnage=input('entrer le nombre maximun de livre a retourner : \n')
numero_du_livre=int(input('entrer le numéro du livre que vous souhaitez avoir : \n'))
params=dict()
params["max"]=nom_personnage
nouvelleurl=api_url+urllib.parse.urlencode(params)
handle_web=urllib.request.urlopen(nouvelleurl)
nouvelle=handle_web.read().decode()
nouvelle=json.loads(nouvelle)
count=0
while count<len(nouvelle):
       if nouvelle[count]['number']==numero_du_livre:
              print(nouvelle[count]['title'])
              break
       count+=1       