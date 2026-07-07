import { OnModuleInit } from '@nestjs/common';
import { Repository } from 'typeorm';
import { CreatePersonagemDto } from './dto/create-personagem.dto';
import { UpdatePersonagemDto } from './dto/update-personagem.dto';
import { Personagem } from './entities/personagem.entity';
export declare class PersonagemService implements OnModuleInit {
    private readonly personagemRepository;
    constructor(personagemRepository: Repository<Personagem>);
    onModuleInit(): Promise<void>;
    create(createPersonagemDto: CreatePersonagemDto): Promise<Personagem>;
    findAll(): Promise<Personagem[]>;
    findOne(id: number): Promise<Personagem>;
    update(id: number, updatePersonagemDto: UpdatePersonagemDto): Promise<Personagem>;
    remove(id: number): Promise<{
        mensagem: string;
    }>;
}
