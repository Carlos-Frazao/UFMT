import { NotFoundException } from '@nestjs/common';
import { Test, TestingModule } from '@nestjs/testing';
import { getRepositoryToken } from '@nestjs/typeorm';
import { Repository } from 'typeorm';
import { Personagem } from './entities/personagem.entity';
import { PersonagemService } from './personagem.service';

describe('PersonagemService', () => {
  let service: PersonagemService;
  let repository: jest.Mocked<Repository<Personagem>>;

  beforeEach(async () => {
    const module: TestingModule = await Test.createTestingModule({
      providers: [
        PersonagemService,
        {
          provide: getRepositoryToken(Personagem),
          useValue: {
            count: jest.fn(),
            save: jest.fn(),
            create: jest.fn(),
            find: jest.fn(),
            findOneBy: jest.fn(),
            remove: jest.fn(),
          },
        },
      ],
    }).compile();

    service = module.get<PersonagemService>(PersonagemService);
    repository = module.get(getRepositoryToken(Personagem));
  });

  it('deve listar personagens ordenados pela ordem de apresentacao', async () => {
    const personagens = [
      {
        id: 1,
        titulo: 'Elliot Alderson',
        conteudo: 'Hacker',
        imagem: 'elliot.jpg',
        afiliacao: 'fsociety',
        ordem: 1,
      },
    ];

    repository.find.mockResolvedValue(personagens);

    await expect(service.findAll()).resolves.toEqual(personagens);
    expect(repository.find).toHaveBeenCalledWith({ order: { ordem: 'ASC' } });
  });

  it('deve criar um personagem', async () => {
    const dto = {
      titulo: 'Whiterose',
      conteudo: 'Lider do Dark Army',
      imagem: 'whiterose.jpg',
      afiliacao: 'dark-army',
      ordem: 2,
    };
    const personagem = { id: 1, ...dto };

    repository.create.mockReturnValue(personagem);
    repository.save.mockResolvedValue(personagem);

    await expect(service.create(dto)).resolves.toEqual(personagem);
    expect(repository.create).toHaveBeenCalledWith(dto);
  });

  it('deve lancar erro quando o personagem nao existir', async () => {
    repository.findOneBy.mockResolvedValue(null);

    await expect(service.findOne(99)).rejects.toBeInstanceOf(
      NotFoundException,
    );
  });
});
