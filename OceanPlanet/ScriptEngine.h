#include <stdio.h>
#include <memory.h>
#include <string.h>

#include "RunningStateData.h"

bool parseStringToBool(const char* str)
{
	if(stricmp(str, "true") == 0 || strnicmp(str, "1", 1)) {
		return true;
	}
	return false;
}

void SetValueForOneAttribute(RunningStateData& model, const char* attribute, const char* valueString)
{
	if (stricmp(attribute, "BombCount") == 0)
	{
		model.BombCount = atoi(valueString);
	}
	else if(stricmp(attribute, "NeedleCount") == 0)
	{
		model.NeedleCount = atoi(valueString);
	}
	else if(stricmp(attribute,"GoalScore") == 0)
	{
		model.GoalScore = atoi(valueString);
	}
	else if(stricmp(attribute, "Life") == 0) {
		model.Life = atoi(valueString);
	}
	else if (stricmp(attribute, "TimeLimit") == 0) {
		model.TimeLimit = atoi(valueString);
	}
	else if (stricmp(attribute, "AllowWeaponType") == 0) {
		model.AllowWeaponType = atoi(valueString);
	}
	else if (stricmp(attribute, "FishProbability") == 0) {
		model.FishProbability = atoi(valueString);
	}
	else if (stricmp(attribute, "SkeletonProbability") == 0) {
		model.propProbabilities[SKELETON_POSSIBILITY_INDEX] = atoi(valueString);
	}
	else if (stricmp(attribute, "HarvestProbability") == 0) {
		model.propProbabilities[HARVEST_POSSIBILITY_INDEX] = atoi(valueString);
	}
	else if (stricmp(attribute, "AccelerateProbability") == 0) {
		model.propProbabilities[ACCELERATE_POSSIBILITY_INDEX] = atoi(valueString);
	}
	else if (stricmp(attribute, "DecelerateProbability") == 0) {
		model.propProbabilities[DECELERATE_POSSIBILITY_INDEX] = atoi(valueString);
	}
	else if (stricmp(attribute, "TreasureProbability") == 0) {
		model.propProbabilities[TREASURE_POSSIBILITY_INDEX] = atoi(valueString);
	}
	else if (stricmp(attribute, "MaxTreasureScore") == 0) {
		model.MaxTreasureScore = atoi(valueString);
	}
	else if (stricmp(attribute, "MinFishVelocity") == 0) {
		sscanf(valueString, "%f", &model.MinFishVelocity);
	}
	else if (stricmp(attribute, "MaxFishVelocity") == 0) {
		sscanf(valueString, "%f", &model.MaxFishVelocity);
	}
	else if (stricmp(attribute, "NeedleVelocity") == 0) {
		sscanf(valueString, "%f", &model.NeedleVelocity); 
	}
	else if (stricmp(attribute, "ArcadeMode") == 0) {
		model.ArcadeMode = parseStringToBool(valueString);
	}
}

void SetAttributeValuesForGameModel(RunningStateData& model, const char* filename)
{
	FILE* file = fopen(filename,"r");
	//if(file == NULL) return;
	char nextChar;	
	char attributeName[30];
	char valueString[20];
	int attributeIndex;
	int valueIndex;

	while((nextChar = fgetc(file)) != EOF)
	{
		attributeIndex = 0;
		valueIndex = 0;
		memset(attributeName, 0, sizeof(attributeName));
		memset(valueString, 0, sizeof(valueString));
		while(nextChar != '=' && nextChar != EOF)
		{
			if(nextChar != ' ') 
				attributeName[attributeIndex++] = nextChar;
			nextChar = fgetc(file);
		}
		nextChar = fgetc(file);
		while(nextChar != '\n' && nextChar != '\r' && nextChar != EOF) {
			if(nextChar != ' ')
				valueString[valueIndex++] = nextChar;
			nextChar = fgetc(file);
		}
		SetValueForOneAttribute(model, attributeName, valueString);
	}

	fclose(file);
}

void InitializeGameModels(RunningStateData* models, int barrierCount) 
{
	int i;
	for(i = 0; i <= barrierCount; i++) {
		char filepath[30];
		char filename[20];
		strcpy(filepath, "script/");
		sprintf(filename, "barrier%d.ini", i);
		strcat(filepath, filename);
		SetAttributeValuesForGameModel(models[i], filepath);
		
		if(models[i].AllowWeaponType & NEEDLE_WEAPON_TYPE) {
			models[i].CurrentWeaponType = NEEDLE_WEAPON_TYPE;
		}
		else {
			models[i].CurrentWeaponType = BOMB_WEAPON_TYPE;
		}
		models[i].Barrier = i;
	}
}