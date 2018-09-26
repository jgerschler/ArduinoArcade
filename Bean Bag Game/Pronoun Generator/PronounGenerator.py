#!/usr/bin/env python

import pygame
import random
import sys

class RandomPronounGenerator(object):
    DISPLAY_WIDTH = 1024
    DISPLAY_HEIGHT = 768

    BLACK = (0,0,0)
    WHITE = (255,255,255)

    def __init__(self):
        self.finished = False

        self.pronoun_list = ["1st Person Singular Subject Pronoun: I", "1st Person Singular Object Pronoun: Me",
                             "1st Person Singular Possessive Adjective: My", "1st Person Singular Possessive Pronoun: Mine",
                             "1st Person Singular Reflexive Pronoun: Myself", "2nd Person Singular Subject Pronoun: You",
                             "2nd Person Singular Object Pronoun: You", "2nd Person Singular Possessive Adjective: Your",
                             "2nd Person Singular Possessive Pronoun: Yours", "2nd Person Singular Reflexive Pronoun: Yourself",
                             "Third Person Singular Masculine Subject Pronoun: He", "Third Person Singular Masculine Object Pronoun: Him",
                             "Third Person Singular Masculine Possessive Adjective: His", "Third Person Singular Masculine Possessive Pronoun: His",
                             "Third Person Singular Masculine Reflexive Pronoun: Himself", "Third Person Singular Feminine Subject Pronoun: She",
                             "Third Person Singular Feminine Object Pronoun: Her", "Third Person Singular Feminine Possessive Adjective: Her",
                             "Third Person Singular Feminine Possessive Pronoun: Hers", "Third Person Singular Feminine Reflexive Pronoun: Herself",
                             "Third Person Singular Neutral Subject Pronoun: It", "Third Person Singular Neutral Object Pronoun: It",
                             "Third Person Singular Neutral Possessive Adjective: Its", "First Person Plural Subject Pronoun: We",
                             "Third Person Singular Neutral Reflexive Pronoun: Itself", "First Person Plural Object Pronoun: Us",
                             "First Person Plural Possessive Adjective: Our", "First Person Plural Possessive Pronoun: Ours",
                             "First Person Plural Reflexive Pronoun: Ourselves", "Second Person Plural Subject Pronoun: You",
                             "Second Person Plural Object Pronoun: You", "Second Person Plural Possessive Adjective: Your",
                             "Second Person Plural Possessive Pronoun: Yours", "Second Person Plural Reflexive Pronoun: Yourselves",
                             "Third Person Plural Subject Pronoun: They", "Third Person Plural Object Pronoun: Them",
                             "Third Person Plural Possessive Adjective: Their", "Third Person Plural Possessive Pronoun: Theirs",
                             "Third Person Plural Reflexive Pronoun: Themselves"]

        pygame.init()
        
        self.game_display = pygame.display.set_mode((RandomPronounGenerator.DISPLAY_WIDTH, RandomPronounGenerator.DISPLAY_HEIGHT))
        pygame.display.set_caption('Random Pronoun Generator')
        self.game_display.fill(RandomPronounGenerator.WHITE)
        pygame.display.update()
        
    def text_objects(self, text, font):
        self.text_surface = font.render(text, True, RandomPronounGenerator.BLACK)
        return self.text_surface, self.text_surface.get_rect()

    def message_display(self, text):
        self.large_text = pygame.font.Font('arial.ttf',32)
        self.text_surf, self.text_rect = self.text_objects(text, self.large_text)
        self.text_rect.center = ((RandomPronounGenerator.DISPLAY_WIDTH/2),(RandomPronounGenerator.DISPLAY_HEIGHT/2))
        self.game_display.blit(self.text_surf, self.text_rect)

    def main_loop(self):
        while not self.finished:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    self.finished = True
                if event.type == pygame.KEYUP:
                    if event.key == pygame.K_SPACE:
                        self.game_display.fill(RandomPronounGenerator.WHITE)
                        self.message_display(random.choice(self.pronoun_list))
                        pygame.display.update()
                    if event.key == pygame.K_ESCAPE:
                        self.finished = True
                        
        pygame.quit()
        sys.exit()


new_pronoun = RandomPronounGenerator()
new_pronoun.main_loop()
